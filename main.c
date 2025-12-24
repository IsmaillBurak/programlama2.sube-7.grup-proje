#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 50

int score( char *studentAnswers,  char *key) { //Oluşturduğumuz score fonksiyonu doğru cevap sayısının döndürür.
    int correct = 0;
    int uz = strlen(key);

    for (int i = 0; i < uz; i++) {
        if (studentAnswers[i] == key[i]) {
            correct++;
        }
    }
    return correct;
}

int main() {
    FILE *fp;
    char key[MAX_QUESTIONS + 1];
    char answers[MAX_QUESTIONS + 1];
    int number;

    int bestScore = 0;
    int bestStudent = -1;

    // Doğru cevap anahtarını gircez
    printf("Cevap Anahtarını giriniz:\n");
    scanf("%s", key);

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    // Dosyayı okutcaz
    while (fscanf(fp, "%d %s", &number, answers) != EOF) {
        int s = score(answers, key);

        if (s > bestScore) {
            bestScore = s;
            bestStudent = number;
        }
    }

    fclose(fp);

    // Sonuç
    if (bestScore == 0) {
        printf("No Champion\n");
    } else {
        printf("Best score :\n");
        printf("%d (%d)\n", bestStudent, bestScore);
    }

    return 0;
}
