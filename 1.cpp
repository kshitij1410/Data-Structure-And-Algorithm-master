#include <bits/stdc++.h>
using namespace std;

class Factory
{
private:
    int name;
    int day;
    int in, out;

public:
    unordered_map<string, vector<vector<int>>> info;
    unordered_map<string, vector<vector<int>>> data;

    void addInfo(string name, int day, int in, int out)
    {
        info[name].push_back({day, in, out});
    }

    void InsertData()
    {
        for (auto ele : info)
        {
            int sum = 0;
            int red = 0;
            int green = 0;
            string name = ele.first;
            for (int i = 0; i < 5; i++)
            {
                int d = ele.second[i][0];
                int k = ele.second[i][1];
                int f = ele.second[i][2];
                int in_hour = k / 100;
                int in_min = k % 100;
                int out_hour = f / 100;
                int out_min = f % 100;

                int temp = out_hour * 60 + out_min - in_hour * 60 - in_min;
                if (temp >= 540)
                    green++;
                else
                    red++;
                sum += temp;
            }

            int average = sum / 5;
            string temp = "";

            if (red == 0)
                temp = "High";
            else if (red == 1 or red == 2)
                temp = "Neutral";
            else
            {
                temp = "low";
            }

            data[name].push_back({average, red, green});
        }
    }

    void flag()
    {
    }
};

int main()
{
    int no_of_student = 5;
    int no_of_days = 5;
    for (int i = 0; i < 5; i++)
    {
        Factory obj;
        string name;
        int day, in, out;
        cin >> name >> day >> in >> out;
        obj.addInfo(name, day, in, out);
    }
    Factory obj;
    obj.InsertData();
    return 0;
}