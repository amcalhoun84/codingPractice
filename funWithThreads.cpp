/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <thread>
#include <pthread.h>
#include <mutex>

#define NUM_THREADS 5

using namespace std;

mutex mtx;

void *PrintHello(void *threadID) {
    
    long tid;
    tid = long(threadID);
    cout << "Hello World: Thread ID, " << tid << endl;
    pthread_exit(NULL);
}

void foo(int z)
{
    for(int i = 0; i < z; i++) cout << "Thread using function pointer is callable.\n";
}

void print_block(int n, char c) {
    
    mtx.lock();
    for(int i=0; i < n; ++i) { cout << c; }
    cout << endl;
    mtx.unlock();
    
}


class thread_obj { 

    public:
    void operator()(int x)
    {
        for(int i = 0; i < x; i++) cout << "Thread using function object is callable.\n";
    }
};


int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    
    for(int i=0; i < NUM_THREADS; i++) 
    {
        cout << "Main(): creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
        if(rc) { 
            cout << "Error, unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    
    // pthread_exit(NULL);
    
    cout << " Threads 1, 2, 3 will operate independently.\n";
    
    // This thread will call a function pointer.
    thread th1(foo, 3);
    // This thread will call a function object.
    thread th2(thread_obj(), 3);
    
    // define a lambda
    
    auto f = [](int x) { 
        for(int i = 0; i < x; i++)
            cout << "Thread using lambda expression is callable.\n";
    };
    
    // call the lambda
    
    thread th3(f, 3);
    
    th1.join();
    th2.join();
    th3.join();
    
    thread th4 (print_block, 50, '!');
    thread th5 (print_block, 50, '*');
    
    th4.join();
    th5.join();
    
    pthread_exit(NULL);

    return 0;
    
}



