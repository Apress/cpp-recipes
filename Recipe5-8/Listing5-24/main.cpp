#include <cinttypes>
#include <cstring>
#include <iostream>

using namespace std;

class Vehicle
{
private:
    char* m_Name{};
    uint32_t m_NumberOfWheels{};

public:
    Vehicle() = default;

    Vehicle(const char* name, uint32_t numberOfWheels)
        : m_NumberOfWheels{ numberOfWheels }
    {
        const uint32_t length = strlen(name) + 1; // Add space for null terminator
        m_Name = new char[length]{};
        strcpy(m_Name, name);
    }

    ~Vehicle()
    {
        if (m_Name != nullptr)
        {
            delete m_Name;
            m_Name = nullptr;
        }
    }

    Vehicle(const Vehicle& other)
    {
        const uint32_t length = strlen(other.m_Name) + 1; // Add space for null terminator
        m_Name = new char[length]{};
        strcpy(m_Name, other.m_Name);

        m_NumberOfWheels = other.m_NumberOfWheels;
    }

    Vehicle& operator=(const Vehicle& other)
    {
        if (m_Name != nullptr)
        {
            delete m_Name;
        }

        const uint32_t length = strlen(other.m_Name) + 1; // Add space for null terminator
        m_Name = new char[length]{};
        strcpy(m_Name, other.m_Name);

        m_NumberOfWheels = other.m_NumberOfWheels;

        return *this;
    }

    Vehicle(Vehicle&& other)
    {
        m_Name = other.m_Name;
        other.m_Name = nullptr;

        m_NumberOfWheels = other.m_NumberOfWheels;
    }

    Vehicle& operator=(Vehicle&& other)
    {
        if (m_Name != nullptr)
        {
            delete m_Name;
        }

        m_Name = other.m_Name;
        other.m_Name = nullptr;

        m_NumberOfWheels = other.m_NumberOfWheels;

        return *this;
    }

    char* GetName()
    {
        return m_Name;
    }

    uint32_t GetNumberOfWheels()
    {
        return m_NumberOfWheels;
    }
};

int main(int argc, char* argv[])
{
    Vehicle myAssignedCar;

    {
        Vehicle myCar{ "myCar", 4 };
        cout << "Vehicle name: " << myCar.GetName() << endl;

        myAssignedCar = move(myCar);
        //cout << "Vehicle name: " << myCar.GetName() << endl;
        cout << "Vehicle name: " << myAssignedCar.GetName() << endl;
    }

    cout << "Vehicle name: " << myAssignedCar.GetName() << endl;

    return 0;
}
