bool solution(string s) {
    bool answer = true;
    bool alpa;

    if (s[0] >= 97 && s[0] <= 122) {
        alpa = true;
    }
    else
        alpa = false;

    if (s.length() == 4 || s.length() == 6) {
        if (alpa) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] >= 97 && s[i] <= 122)
                    continue;
                else {
                    answer = false;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] >= 48 && s[i] <= 57)
                    continue;
                else {
                    answer = false;
                    break;
                }
            }
        }
    }
    else {
        answer = false;
    }
    return answer;
}
