#include <ctime>
#include <cstring>
#include <cstdlib>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;
const int range = 20;
bool passedexam(int answer);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    std::srand(std::time(0));

    Worker* in[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter s: singer "
            << "t: singing waiter q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL) 
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':
            in[ct] = new Waiter;
            break;
        case 's':
            in[ct] = new Singer;
            break;
        case 't':
            in[ct] = new SingingWaiter;
            break;
        }
        cin.get();
        in[ct]->Set();
    }

    QueueTP<Worker*> exam(ct);
    Worker* out[SIZE];

    int total_exam_mins = 0;
    int empl_exam_mins = 1;
    int failed = 0;
    int passed = 0;
    int index = 0;
    bool correct_answer = false;

    int timelimit = 10;

    while (!exam.isfull())
    {
        exam.enqueue(in[index]);
        index++;
    }

    index = 0;

    cout << "\nThe number of employees taking exam: "
        << exam.queuecount() << ", Exam time limit = "
        << timelimit << " minutes." << endl;

    while (!exam.isempty()) 
    {
        correct_answer = passedexam(10);

        if (correct_answer &&
            (empl_exam_mins < timelimit) &&
            !exam.isempty()) 
        {
            exam.dequeue(out[index]);
            cout << "\nPASSED! Employee [" 
                << out[index]->Worker::Name() 
                << ", " << out[index]->Worker::ID()
                << "], exam time: " << empl_exam_mins
                << "minutes.";
            empl_exam_mins = 1;
            index++;
            passed++;
        }
        else if (!correct_answer &&
            (empl_exam_mins > timelimit) && 
            !exam.isempty()) 
        { 
            exam.dequeue(out[index]);
            cout << "\nFAILED! Employee ["
                << out[index]->Worker::Name()
                << ", " << out[index]->Worker::ID()
                << "], exam time: " << empl_exam_mins
                << " minutes.";
            empl_exam_mins = 1;
            index++;
            failed++;
        }
        else if (!correct_answer && !exam.isempty())
            empl_exam_mins++;         

        total_exam_mins++;
    }
    cout << "\n\nTotal exam time: " << total_exam_mins
        << " minutes.";
    cout << "\nPassed: " << passed;
    cout << "\nFailed: " << failed;

    cout << "\n\nEmployee overview: \n\n";
    for (int i = 0; i < ct; i++) 
    {
        out[i]->Show();
        delete in[i];
        cout << endl;
    }

    cout << "\nBye.";
    cin.get();
    cin.get();
    return 0;
}

bool passedexam(int answer)
{
    if ((std::rand() * range / RAND_MAX) == answer)
        return true;
    else
        return false;
}
