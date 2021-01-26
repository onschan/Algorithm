string solution(string new_id) {
    string answer;
    string rst;
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 65 && new_id[i] <= 90) {
            answer.push_back(new_id[i] + 32);
        }
        else if (new_id[i] == 45 || new_id[i] == 46 || new_id[i] == 95) {
            answer.push_back(new_id[i]);
        }
        else if (new_id[i] >= 97 && new_id[i] <= 122) {
            answer.push_back(new_id[i]);
        }
        else if (new_id[i] >= 48 && new_id[i] <= 57) {
            answer.push_back(new_id[i]);
        }
    }

    if (answer.length() == 0) answer.push_back('a');

    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] >= 65 && answer[i] <= 90) {
            rst.push_back(answer[i] + 32);
        }
        else if (answer[i] == 45 || answer[i] == 95) {
            rst.push_back(answer[i]);
        }
        else if (answer[i] >= 97 && answer[i] <= 122) {
            rst.push_back(answer[i]);
        }
        else if (answer[i] >= 48 && answer[i] <= 57) {
            rst.push_back(answer[i]);
        }
        else if (answer[i] == 46) {
            rst.push_back(answer[i]);
            int x = i + 1;
            while (x < answer.length() && answer[x++] == 46) {
                i++;
            }
        }
    }

    while (!answer.empty()) {
        answer.pop_back();
    }

    if (rst.length() == 0) answer.push_back('a');
    else {
        for (int i = 0; i < rst.length(); i++) {
            if (i == 0 && rst[i] == '.')
                continue;
            answer.push_back(rst[i]);
        }
    }

    if (answer.length() == 0) answer.push_back('a');

    while (answer.length() >= 16) {
        answer.pop_back();
    }

    if (answer[answer.length() - 1] == '.') answer.pop_back();

    if (answer.length() == 0) answer.push_back('a');

    while (answer.length() <= 2) {
        answer.push_back(answer[answer.length() - 1]);
    }

    return answer;
}
