#include "arrqueue.h"

Queue::~Queue()
{
    delete[] queue;
    queue = nullptr;
    begin = 0;
    end = 0;
    s = 0;
}

void Queue::add(const int& a)
{
    if (end < s && s != 0) {
        queue[end++] = a;
        return;
    }
    else if (s == 0) {
        *this = Queue(1);
        queue[0] = a;
        end++;
        return;
    }
    else if (end >= s) {
        int *q = new int[s * 2];
        for (ptrdiff_t i(begin); i < end; i++) {
            q[i - begin] = queue[i];
        }
        end = end - begin;
        q[end++] = a;
        begin = 0;
        delete[] queue;
        queue = q;
        s = s * 2;
    }
}

void Queue::copy(const Queue& source, Queue& goal)
{
    goal.s = source.size();
    ptrdiff_t index = 0;
    for (ptrdiff_t i(source.begin); i < source.end; ++i) {
        goal.queue[index++] = source.queue[i];
    }
    goal.begin = 0;
    goal.end = source.end - source.begin;
}

void Queue::pop()
{
    if (begin != end) {
        begin++;
    }
}

Queue::Queue(const Queue& q)
{
    queue = new int[q.size()];
    copy(q, *this);
}

Queue& Queue::operator=(const Queue& q)
{
    if (q.queue == queue) return *this;
    if (queue != nullptr) delete[] queue;
    queue = new int[q.size()];
    copy(q, *this);
    return *this;
}

Queue::Queue(const int& size)
{
    if (size < 0) {
        throw std::invalid_argument("Invalid size of Queue\n");
    }
    queue = new int[size];
    s = size;
}

int& Queue::front()
{
    if (begin == end) {
        throw std::out_of_range("Invalid use of front function in Queue\n");
    }
    else return queue[begin];
}