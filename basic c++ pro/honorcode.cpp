//
// Created by 10154 on 2022/9/22.
//
#include<iostream>
using namespace std;
char *str = "PLEASE NOTE THAT, BY SUBMITTING YOUR CODE TO THIS PROBLEM (NO MATTER THE RESULT IS), YOU ARE AGREEING TO ALL OF THE FOLLOWING TERMS:\n"
            "\n"
            "1. YOU MAY NOT PLAGIARIZE CODE THAT ARE NOT AUTHORED BY YOURSELF.\n"
            "2. IF YOU HAVE EVER REFERRED TO ANY OTHER PERSON\'S CODE OR IDEAS, YOU MUST CLEARLY INDICATE THE SOURCE WITH A COMMENT AT THE POINT OF USE. HOWEVER, YOU ARE NOT ALLOWED TO REFER TO CODE AUTHORED BY ANYONE WHO IS CURRENTLY TAKING OR HAS ALREADY TAKEN (NO MATTER PASSED OR FAILED) THIS COURSE.\n"
            "3. IF ANYONE ASKS FOR YOUR HELP WITH A PROBLEM ON THE OJ, YOU MAY NOT PROVIDE THAT PERSON WITH YOUR SOURCE CODE.\n"
            "4. YOU MAY NOT MALICIOUSLY HACK THE OJ SYSTEM, INCLUDING BUT NOT LIMITED TO (1) SUBMITTING CODE TOO FREQUENTLY, (2) PERFORMING UNNECESSARY SYSCALLS IN YOUR CODE, OR (3) TRYING TO EXPLOIT KERNEL VULNERABILITIES. YOU CAN CONTACT THE TEACHING ASSISTANT BEFORE DOING ANYTHING THAT YOU THINK CAN BE UNSAFE TO THE OJ SYSTEM.\n"
            "5. YOUR OJ SCORE WILL BE COUNTED AS ZERO IF YOU VIOLATE ANY OF THE RULES ABOVE.";
int main(){
    char a;
    cin >> a;
    if(a == 'A') cout << str;
    else {
        int i = 0;
        while(str[i] != '\0' )
            if(str[i] >= 'A' && str[i] <= 'Z')
                printf("%c", str[i++] + 'a' - 'A');
            else
                cout<< str[i++];

    }
}
