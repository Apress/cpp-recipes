#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class SmallBlockAllocator
{
public:
    static const unsigned int BLOCK_SIZE{ 32 };

private:
    static const unsigned int NUM_BLOCKS{ 1024 };
    static const unsigned int PAGE_SIZE{ NUM_BLOCKS * BLOCK_SIZE };

    class Page
    {
    private:
        char m_Memory[PAGE_SIZE];
        bool m_Free[NUM_BLOCKS];
        Page* m_pNextPage;

    public:
        Page()
            : m_pNextPage{ nullptr }
        {
            memset(m_Free, 1, NUM_BLOCKS);
        }

        ~Page()
        {
            if (m_pNextPage)
            {
                delete m_pNextPage;
                m_pNextPage = nullptr;
            }
        }

        void* Alloc()
        {
            void* pMem{ nullptr };

            for (unsigned int i{ 0 }; i < NUM_BLOCKS; ++i)
            {
                if (m_Free[i] == true)
                {
                    m_Free[i] = false;
                    pMem = &m_Memory[i * BLOCK_SIZE];
                    break;
                }
            }

            if (pMem == nullptr)
            {
                if (m_pNextPage == nullptr)
                {
                    m_pNextPage = new Page();
                }

                pMem = m_pNextPage->Alloc();
            }

            return pMem;
        }

        bool Free(void* pMem)
        {
            bool freed{ false };

            bool inPage{ pMem >= m_Memory &&
                pMem <= &m_Memory[(NUM_BLOCKS * BLOCK_SIZE) - 1] };
            if (inPage)
            {
                unsigned int index{
                    (reinterpret_cast<unsigned int>(pMem)-
                     reinterpret_cast<unsigned int>(m_Memory)) / BLOCK_SIZE };
                m_Free[index] = true;
                freed = true;
            }
            else if (m_pNextPage)
            {
                freed = m_pNextPage->Free(pMem);

                if (freed && m_pNextPage->IsEmpty())
                {
                    Page* old = m_pNextPage;
                    m_pNextPage = old->m_pNextPage;
                    old->m_pNextPage = nullptr;
                    delete m_pNextPage;
                }
            }

            return freed;
        }

        bool IsEmpty() const
        {
            bool isEmpty{ true };

            for (unsigned int i{ 0 }; i < NUM_BLOCKS; ++i)
            {
                if (m_Free[i] == false)
                {
                    isEmpty = false;
                    break;
                }
            }

            return isEmpty;
        }
    };

    Page m_FirstPage;

public:
    SmallBlockAllocator() = default;

    void* Alloc()
    {
        return m_FirstPage.Alloc();
    }

    bool Free(void* pMem)
    {
        return m_FirstPage.Free(pMem);
    }
};

static SmallBlockAllocator sba;

void* operator new(size_t numBytes, const std::nothrow_t& tag) noexcept
{
    void* pMem{ nullptr };

    if (numBytes <= SmallBlockAllocator::BLOCK_SIZE)
    {
        pMem = sba.Alloc();
    }
    else
    {
        pMem = malloc(numBytes);
    }

    return pMem;
}

void* operator new[](size_t numBytes, const std::nothrow_t& tag) noexcept
{
    void* pMem{ nullptr };

    if (numBytes <= SmallBlockAllocator::BLOCK_SIZE)
    {
        pMem = sba.Alloc();
    }
    else
    {
        pMem = malloc(numBytes);
    }

    return pMem;
}

void operator delete(void* pMemory) noexcept
{
    if (!sba.Free(pMemory))
    {
        free(pMemory);
    }
}

void operator delete[](void* pMemory) noexcept
{
    if (!sba.Free(pMemory))
    {
        free(pMemory);
    }
}

int main(int argc, char* argv[])
{
    const unsigned int NUM_ALLOCS{ 2148 };
    int* pInts[NUM_ALLOCS];

    for (unsigned int i{ 0 }; i < NUM_ALLOCS; ++i)
    {
        pInts[i] = new int;
        *pInts[i] = i;
    }

    for (unsigned int i{ 0 }; i < NUM_ALLOCS; ++i)
    {
        delete pInts[i];
        pInts[i] = nullptr;
    }

    return 0;
}
