int main() {

    Stack s;
    int i = 1;

    display(s);
    cout << endl;

    while (not full(s)) {
        push(s, i *= 2);
    }

    cout << "top  : " << top(s) << endl;
    cout << "size : " << size(s) << endl;
    cout << endl;

    display(s);
    cout << endl;

    while (not empty(s)) {
        pop(s);
    }

    display(s);
    cout << endl;
}
