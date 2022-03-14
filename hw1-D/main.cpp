#include <iostream>
#include "Task.h"
#include "Server.h"
using namespace std;

int main()
{
    int N;
    int M;
    cin >> N >> M;
    Server server(N, M);
    int o;
    cin >> o;
    int cur_time = 0;
    for(int i = 0; i < o; i++) 
    {
        int t, d, n, m;
        char o;
        char s[30];
        cin >> t >> o;
        scanf("%s", s);
        for (int j = 0; j < t - cur_time; j++)
            server.tick();
        cur_time = t;
        if(o == 's')
        {
            cin >> n >> m >> d;
            Task task(s, d, n, m);
            if(server.submit_task(task))
            {
                cout << "Accepted " << s << endl;
            }
            else
            {
                cout << "Rejected " << s << endl;
            }
        }
        else if(o == 'c')
        {
            if(server.cancel_task(s))
            {
                cout << "Cancelled " << s << endl;
            }
            else
            {
                cout << "Not found " << s << endl;
            }
        }
        else
        {
            cout << "Invalid operation" << endl;
        }
    }
    return 0;
}