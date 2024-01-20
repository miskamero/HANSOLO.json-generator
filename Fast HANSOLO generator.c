#include <stdio.h>

const char* jsonData = "{\"data\":[";
const char* hansoloData = "\"HANSOLO\"";

void generateJSON(FILE* file, int* repetitions) {
    fprintf(file, "%s", jsonData);

    for (int i = 0; i < *repetitions; i++) {
        fprintf(file, "%s", hansoloData);
        if (i < *repetitions - 1) {
            fprintf(file, ",");
        }
    }

    fprintf(file, "]}");
}

int main() {
    int repetitions = 1000000000;
    FILE* file = fopen("HANSOLO.json", "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    generateJSON(file, &repetitions);

    fclose(file);
    printf("HANSOLO.json created successfully with %d repetitions.\n", repetitions);

    return 0;
}
