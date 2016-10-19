#include <future>
#include <iostream>

using namespace std;

using FactorialPromise = promise< long long > ;

long long Factorial(unsigned int value)
{
    this_thread::sleep_for(chrono::seconds(2));
    return value == 1
        ? 1
        : value * Factorial(value - 1);
}

void ThreadTask(FactorialPromise& threadPromise, unsigned int value)
{
    threadPromise.set_value(Factorial(value));
}

int main(int argc, char* argv[])
{
    using namespace chrono;

    FactorialPromise promise;
    future<long long> taskFuture{ promise.get_future() };

    thread taskThread{ ThreadTask, std::move(promise), 3 };

    while (taskFuture.wait_until(system_clock::now() + seconds(1)) != future_status::ready)
    {
        cout << "Still Waiting!" << endl;
    }

    cout << "Factorial result was " << taskFuture.get() << endl;

    taskThread.join();

    return 0;
}
