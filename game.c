#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/************************************************** 가위 바위 보 **************************************************/

// 가위 바위 보 함수
void rock_Scissors_Paper() {
    printf("\nRock_Scissors_Paper Game\n");
    printf("=============================\n");
    char again = ' ';

    // 게임 반복
    while ((again != 'N') && (again != 'n')) {
        int computer_choice = c_choice();
        int user_choice;

        // 사용자 선택
        printf("선택하세요\n");
        printf("1.가위  2.바위  3.보\n");

        // 유효한 입력 검사
        while (1) {
            if (scanf("%d", &user_choice) != 1 || user_choice < 1 || user_choice > 3) {
                printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
                while (getchar() != '\n'); // 입력 버퍼 비우기
            }
            else {
                break;
            }
        }

        // 컴퓨터 선택 함수 호출
        process(computer_choice, user_choice);

        // 게임 재시작 여부 확인
        printf("한번 더 플레이 하시겠습니까? (y/n)\n>> ");
        scanf(" %c", &again);
    }

    main();
}

// 컴퓨터 선택 함수 (1-3 사이 난수 발생)
int c_choice() {
    return (rand() % 3) + 1;
}

// 선택 결과 문자열 변환 함수
void choiceToString(int choice, char* result) {
    switch (choice) {
    case 1:
        strcpy(result, "가위");
        break;
    case 2:
        strcpy(result, "바위");
        break;
    case 3:
        strcpy(result, "보");
        break;
    default:
        strcpy(result, "알 수 없음");
        break;
    }
}

// 승부 판정 함수
int process(int computer_choice, int user_choice) {
    char computer[10]; // 컴퓨터 선택 문자열을 저장할 배열
    char user[10];     // 사용자 선택 문자열을 저장할 배열

    // 선택 -> 문자열 변환
    choiceToString(computer_choice, computer);
    choiceToString(user_choice, user);

    printf("Computer's choice: %s\n", computer);
    printf("Your choice: %s\n", user);

    // 승패 조건
    if (computer_choice == user_choice) {
        printf("비겼습니다!\n");
        return 0;
    }
    else if ((computer_choice == 1 && user_choice == 3) ||
        (computer_choice == 2 && user_choice == 1) ||
        (computer_choice == 3 && user_choice == 2)) {
        printf("컴퓨터가 이겼습니다!\n");
        return 0;
    }
    else {
        printf("사용자가 이겼습니다!\n");
        return 0;
    }
}

/************************************************** 사칙 연산 게임 **************************************************/

// 난수 정의, 사칙연산 로직 정의, 정답유무와 점수계산 로직 정의 함수
void generateProblemAndCalculateScore(int* score, int levelscore, int operation) {
    int num1 = rand() % 99 + 1; // 1 ~ 99 숫자 랜덤
    int num2 = rand() % 99 + 1;
    int answer, userAnswer;

    switch (operation) {
    case 0: // 더하기
        answer = num1 + num2;
        printf("%d + %d = ", num1, num2);
        break;
    case 1: // 빼기
        answer = num1 - num2;
        printf("%d - %d = ", num1, num2);
        break;
    case 2: // 곱하기
        answer = num1 * num2;
        printf("%d * %d = ", num1, num2);
        break;
    case 3: // 나누기
        answer = num1 / num2;
        printf("%d / %d = ", num1, num2);
        break;
    default:
        return;
    }

    scanf("%d", &userAnswer);

    // 정답 확인 및 점수 계산
    if (userAnswer == answer) {
        printf("정답입니다!\n");
        (*score) += levelscore;
    }
    else {
        while (getchar() != '\n'); // 입력 버퍼 비우기
        printf("오답입니다. 정답은 %d.\n", answer);
    }
}

// 등급 판단 함수
void calculateGradeAndPrint(int score, int level) {
    int grade;

    // 점수와 레벨에 따른 등급 판별
    if ((score >= 9 && level == 3) || (score == 6 && level == 2) || (score == 3 && level == 1)) {
        grade = 1;
    }
    else if ((score >= 6 && level == 3) || (score == 4 && level == 2) || (score == 2 && level == 1)) {
        grade = 2;
    }
    else if ((score >= 3 && level == 3) || (score == 2 && level == 2) || (score == 1 && level == 1)) {
        grade = 3;
    }
    else {
        grade = 0;
    }

    printf("당신의 점수는 %d점입니다. %d등급 입니다.\n", score, grade);
}

// 사칙연산 게임 시작 함수
void runMathQuiz() {
    printf("\nFour basic operations Game\n");
    printf("=============================\n");
    char again = ' ';

    while ((again != 'N') && (again != 'n')) {
        int level, score = 0;

        // 레벨 입력
        printf("레벨을 선택하세요 (1-3): ");
        scanf("%d", &level);

        // 레벨 예외 처리
        if (level < 1 || level > 3) {
            printf("레벨을 잘못 입력하였습니다.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        int levelscore = level;

        // 4칙연산 문제 출제 및 점수 계산
        for (int i = 0; i < 3; i++) {
            int operation = rand() % 4;
            generateProblemAndCalculateScore(&score, levelscore, operation);
        }

        calculateGradeAndPrint(score, level);

        // 게임 재시작 여부 확인
        printf("한번 더 플레이 하시겠습니까? (y/n)\n>> ");
        scanf(" %c", &again);
    }

    main();
}

/************************************************** 야구 게임 **************************************************/

//야구게임 함수
void baseballGame() {
    printf("\nBaseball Game\n");
    printf("=============================\n");
    char again = ' ';

    while ((again != 'N') && (again != 'n')) {
        int result = generateUniqueThreeDigitNumber(); //정답 생성
        int opportunity = 10; // 시도 가능 횟수

        //야구 게임 시작
        strike_ball(result, opportunity);

        //게임 지속 여부 확인
        printf("한번 더 플레이 하시겠습니까? (y/n)\n>> ");
        scanf(" %c", &again);
    }
    main();
}

//정답 생성 함수 (서로 다른 3개의 숫자로 이루어진 3자리 난수 발생 함수)
int generateUniqueThreeDigitNumber() {
    int num1, num2, num3;
    int result;

    // 서로 다른 숫자를 가진 3자리 수 생성
    do {
        num1 = rand() % 9 + 1;  // 첫 번째 자리 수는 1~9 사이의 난수
        num2 = rand() % 10;     // 두 번째 자리 수는 0~9 사이의 난수
        num3 = rand() % 10;     // 세 번째 자리 수는 0~9 사이의 난수

        result = num1 * 100 + num2 * 10 + num3;
    } while (num1 == num2 || num1 == num3 || num2 == num3); // 모든 숫자가 서로 다른지 확인

    return result;
}

//사용자 입력 스트라이크 볼 판별 함수
int strike_ball(int result, int opportunity_left) {
    while (opportunity_left != 0) {
        int strikes = 0;
        int balls = 0;

        int answer;
        printf("3자리 숫자를 입력하세요\n");
        while (1) {
            if (scanf("%d", &answer) != 1) {
                // 정수가 아닌 값이 입력된 경우
                printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
                while (getchar() != '\n'); // 입력 버퍼를 비움
            }
            else if (answer < 100 || answer > 999) {
                // 범위를 벗어난 숫자가 입력된 경우
                printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
            }
            else {
                break; // 유효한 입력값이 입력된 경우 반복문 종료
            }
        }

        // 각 자리 숫자를 추출하기 위한 변수들
        int comp_digit1 = result / 100;
        int comp_digit2 = (result % 100) / 10;
        int comp_digit3 = result % 10;

        int guess_digit1 = answer / 100;
        int guess_digit2 = (answer % 100) / 10;
        int guess_digit3 = answer % 10;

        // 각 자리 숫자 비교하여 스트라이크와 볼 판정
        if (comp_digit1 == guess_digit1) strikes++;
        if (comp_digit2 == guess_digit2) strikes++;
        if (comp_digit3 == guess_digit3) strikes++;

        if (comp_digit1 == guess_digit2 || comp_digit1 == guess_digit3) balls++;
        if (comp_digit2 == guess_digit1 || comp_digit2 == guess_digit3) balls++;
        if (comp_digit3 == guess_digit1 || comp_digit3 == guess_digit2) balls++;

        // 결과 출력
        printf("Strikes: %d, Balls: %d\n", strikes, balls);

        if (strikes == 3) {
            printf("정답입니다!\n");
            break;
        }

        opportunity_left = opportunity_left - 1;

        if (opportunity_left == 0) {
            printf("게임에서 지셨습니다.\n");
            printf("정답은 %d 였습니다.\n", result);
            break;
        }

        // 남은 기회 출력
        printf("Attempts left: %d\n", opportunity_left);
    }
}
/************************************************** 업다운게임 게임 **************************************************/

//업다운게임 함수
int startUdgame()
{
    int num = rand() % 100 + 1; // 1 ~ 100 반환

    int answer = 0;
    int chance = 5;

    while (chance >= 0) {
        if (chance == 0) {
            printf("게임에서 지셨습니다.\n");
            printf("정답은 %d 였습니다.\n", num);
            break;
        }

        printf("남은기회: %d\n", chance);
        printf("숫자를 맞춰보세요. (1~100)\n");
        printf("\n");

        // ** OR조건 ** //
        if ((scanf("%d", &answer) != 1) || (answer < 1 || answer > 100)) {
            printf("잘못된 입력입니다. 올바른 범위의 숫자를 입력해주세요.\n");
            while (getchar() != '\n');
            chance++; // 기회 감소 방지
            continue;
        }

        // 종료 및 게임로직 분기
        if (answer == num) {
            printf("정답입니다!\n");
            break;
        }
        else if (answer > num) {
            printf("↓down↓\n\n");
            chance--;
        }
        else if (answer < num) {
            printf("↑up↑\n\n");
            chance--;
        }
        else
        {
            break;
        }
    }
}

void udGame() {
    printf("\nUP&Down Game\n");
    printf("=============================\n");
    char again = ' ';

    while ((again != 'N') && (again != 'n')) {
        startUdgame();

        //게임 지속 여부 확인
        printf("한번 더 플레이 하시겠습니까? (y/n)\n>> ");
        scanf(" %c", &again);
    }
    main();
}

/************************************************** 메인 함수 **************************************************/
// 메인 함수
int main() {
    srand(time(NULL)); // 난수 발생기 초기화
    printf("*******       *      *******  **       **\n");
    printf("*            * *     *        * *     * *\n");
    printf("*   ****    *   *    ******   *  *   *  *\n");
    printf("*      *   *******   *        *   * *   *\n");
    printf(" ******   *       *  *******  *    *    *\n");
    printf("=============================\n");
    printf("=  **게임을 골라주세요.**   =\n=  1.가위바위보             =\n=  2.사칙연산               =\n=  3.야구게임               =\n=  4.업다운게임             =\n=  5.종료                   =\n");
    printf("=============================\n");
    int user_choice;

    while (1) {
        if (scanf("%d", &user_choice) != 1) {
            // 정수가 아닌 값이 입력된 경우
            printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
            while (getchar() != '\n'); // 입력 버퍼를 비움
        }
        else if (user_choice < 1 || user_choice > 5) {
            printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
            scanf("%d", &user_choice);
        }
        else {
            break; // 유효한 입력값이 입력된 경우 반복문 종료
        }
    }

    if (user_choice == 1) {
        rock_Scissors_Paper();
    }

    else if (user_choice == 2) {
        runMathQuiz();
    }

    else if (user_choice == 3) {
        baseballGame();
    }

    else if (user_choice == 4) {
        udGame();
    }

    else if (user_choice == 5) {
        exit(0);
    }

    return 0;
}
