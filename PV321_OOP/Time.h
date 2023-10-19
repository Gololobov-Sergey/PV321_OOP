#pragma once
#include<iostream>

using namespace std;

class Time
{
private:

    int hour   = 0;
    int minute = 0;
    int second = 0;

public:
    Time();

    Time(int sec);

    Time(int min, int sec);

    Time(int hour_, int min, int sec);

    void setSecond(int sec);

    int getSecond() const;

    void setMinute(int min);

    int getMinute() const;

    void setHour(int hour_);

    int getHour() const;

    void print() const;

    void setTime(int hour_, int min, int sec);
};

Time::Time()
{
    hour = minute = second = 0;
}

Time::Time(int sec)
{
    setTime(0, 0, sec);
}

Time::Time(int min, int sec)
{
    setTime(0, min, sec);
}

Time::Time(int hour_, int min, int sec)
{
    setTime(hour_, min, sec);
}

void Time::setHour(int hour_)
{
    setTime(hour_, minute, second);
}

void Time::setMinute(int min)
{
    setTime(hour, min, second);
}

void Time::setSecond(int sec)
{
    setTime(hour, minute, sec);
}

int Time::getSecond() const
{
    return second;
}

int Time::getMinute() const
{
    return minute;
}

int Time::getHour() const
{
    return hour;
}

void Time::print() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}

void Time::setTime(int hour_, int min, int sec)
{
    if (hour_ < 24 && hour_ >= 0)
    {
        if (min < 60 && min >= 0)
        {
            if (sec < 60 && sec >= 0)
            {
                hour = hour_;
                minute = min;
                second = sec;
            }
        }
    }

}

