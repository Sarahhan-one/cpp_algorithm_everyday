#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

typedef struct _box {
    int num; 
    struct _box* prev; 
    struct _box* next;
}box;

int q, beltCnt, boxCnt; 
vector<list<box*>> belts;
vector<box> boxes;

void printAll() {
    for (int i = 1; i < belts.size(); i++) {
         cout << i << " line : ";
        for (box* cur : belts[i]) {
            cout << cur->num << ' ';
        }
        cout << '\n';
    }
}

void buildFactory() { //100
    cin >> beltCnt >> boxCnt; 

    vector<vector<int>> beltsTemp(beltCnt + 1);
    belts.resize(beltCnt + 1);
    boxes.resize(boxCnt + 1);

    int idx;
    for (int i = 1; i <= boxCnt; i++) {
        cin >> idx; 
        beltsTemp[idx].push_back(i);
    }

    for (int i = 1; i <= beltCnt; i++) {
        for (auto curBox : beltsTemp[i]) {
            if (belts[i].size() > 0) {
                boxes[curBox] = {curBox, belts[i].back(), nullptr};
                belts[i].back()->next = &boxes[curBox];
            }
            else {
                boxes[curBox] = {curBox, nullptr, nullptr};
            }
            belts[i].push_back(&boxes[curBox]);
        }
    }
}

void moveAll() { //200 
    int src, dst;
    cin >> src >> dst;

    if (belts[src].empty()) {
        cout << belts[dst].size() << '\n';
        return;
    }

    if (!belts[dst].empty()) { // change pointer connections only if dest is not empty
        box* sourceEnd = belts[src].back(); 
        box* destStart = belts[dst].front();

        sourceEnd->next = destStart;
        destStart->prev = sourceEnd;
    }

    belts[dst].splice(belts[dst].begin(), belts[src]);

    cout << belts[dst].size() << '\n';
}

void replaceFront() { //300
    int src, dst;
    cin >> src >> dst;

    box* box_s = nullptr;
    box* box_d = nullptr;
    box* box_s_next = nullptr;
    box* box_d_next = nullptr;

    if (!belts[src].empty()) {
        box_s = belts[src].front();
        box_s_next = box_s->next;
        belts[src].pop_front();
    }
    if (!belts[dst].empty()) {
        box_d = belts[dst].front();
        box_d_next = box_d->next;
        belts[dst].pop_front();
    }
    
    if (box_s) {
        belts[dst].push_front(box_s);
        box_s->next = box_d_next;
    }
    if (box_d) {
        belts[src].push_front(box_d);
        box_d->next = box_s_next;
    }

    if (box_s_next) {
        box_s_next->prev = box_d;
    }
    if (box_d_next) {
        box_d_next->prev = box_s;
    }

    cout << belts[dst].size() << '\n';
}

void share() { //400
    int src, dst;
    cin >> src >> dst;

    int n = belts[src].size();
    if (n <= 1) {
        cout << belts[dst].size() << '\n';
        return;
    }

    auto split_point = belts[src].begin(); 
    advance(split_point, n/2);

    box* tail = *prev(split_point);
    box* src_new_head = *split_point;
    box* dst_old_head = belts[dst].empty() ? nullptr : belts[dst].front();

    if (dst_old_head) {
        tail->next = dst_old_head;
        dst_old_head->prev = tail;
    } else {
        tail->next = nullptr;
    }
    src_new_head->prev = nullptr;

    belts[dst].splice(belts[dst].begin(), belts[src], belts[src].begin(), split_point);

    cout << belts[dst].size() << '\n';
}

void getInfo() { //500
    int idx;
    cin >> idx;

    int prev = boxes[idx].prev == nullptr ? -1 : boxes[idx].prev->num;
    int next = boxes[idx].next == nullptr ? -1 : boxes[idx].next->num;

    cout << prev + (2 * next) << endl;
}

void getInfoBelt() { //600
    int idx; 
    cin >> idx;

    int size = belts[idx].size();
    int front = size > 0 ? belts[idx].front()->num : -1;
    int back = size > 0 ? belts[idx].back()->num : -1;

    cout << front + (2*back) + (3*size) << '\n';
}

int main() {
    cin >> q; 
    for (int i = 0; i < q; i++) {
        int command; 
        cin >> command;
        switch (command) {
            case 100: 
                buildFactory();
                break; 
            case 200:
                moveAll();
                break;
            case 300:
                replaceFront();
                break;
            case 400:
                share();
                break;
            case 500:
                getInfo();
                break;
            case 600:
                getInfoBelt();
                break;
        }
    }
}