#include <iostream>
#include<queue>
#include<Windows.h>

using namespace std;

struct PrintJob {
   char user[20];
   time_t timestamp;
};

class PrinterQueue {
private:
    queue<PrintJob> jobQueue;
    queue<PrintJob> printHistory;

public:
    void enqueueJob(const PrintJob& job) {
        jobQueue.push(job);
    }

    void printNextJob() {
        if (!jobQueue.empty()) {
            PrintJob job = jobQueue.front();
            jobQueue.pop();
            int i = 0;
            char timeStr[30];
            ctime_s(timeStr, sizeof(timeStr), &job.timestamp);
            while (i != 5) {
                Sleep(200);
                system("cls");
                cout << "Printing..." << endl;
                Sleep(200);
                system("cls");
                
                cout << "Printing.." << endl;
                Sleep(200);
                system("cls");
                cout << "Printing." << endl;i++;
            }

            cout << "User: " << job.user
                << "\nTime: " << timeStr << endl;
            
            Sleep(500);
            printHistory.push(job);
        }
        else {
            cout << "Print queue is empty" << endl;
        }
    }

    void printPrintHistory() {
        system("cls");
        cout << "Print history:" << endl << endl;
       
        while (!printHistory.empty()) {

            PrintJob job;
            job = printHistory.front();
            printHistory.pop();
            char timeStr[30];
            ctime_s(timeStr, sizeof(timeStr), &job.timestamp);
        cout << "User: " << job.user
            << "\nTime: " << timeStr << endl;
        }
    }
};

int main() {
    PrinterQueue printer;

    PrintJob job1 = { "User1", time(nullptr) };
    printer.enqueueJob(job1);
    Sleep(1000);                                // чтоб время отличалось
    PrintJob job2 = { "User2", time(nullptr) };
    printer.enqueueJob(job2);
    Sleep(1000);
    PrintJob job3 = { "User3", time(nullptr) };
    printer.enqueueJob(job3);

    printer.printNextJob();
    printer.printNextJob();
    printer.printNextJob();

    printer.printPrintHistory();

}
