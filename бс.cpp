int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}


void task1() {
    int num1, num2;
    cout << "������� ��� �����: ";
    cin >> num1 >> num2;
    int count1 = countDigits(num1);
    int count2 = countDigits(num2);

    if (count1 > count2) {
        cout << "� ������ ����� ������ ����.\n";
    }
    else if (count2 > count1) {
        cout << "�� ������ ����� ������ ����.\n";
    }
    else {
        cout << "��� ����� ����� ���������� ���������� ����.\n";
    }
}
