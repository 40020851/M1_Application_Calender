#include <calfunction.h>


void calendar(int y, int m){
    FILE *fp;
    Note* notes, note;
    int len, j, hasNote = 0;
    char choice;
    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su   Mo   Tu   We   Th   Fr   Sa";
    int DayOfMonth[] =
        { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;
 
    weekOfTopDay = days(y, m, 1) % 7;
 
    fp = fopen("note.bin", "rb");
    if (fp == NULL) {
      printf("Couldn't read notes\n");
    }
    len = 0;
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        len++;
      }
    }
    rewind(fp);
    j = 0;
    notes = (Note*) malloc (sizeof(Note) * len);
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        notes[j] = note;
        j++;
      }
    }
 
    fclose(fp);
 
    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);
 
    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        hasNote = 0;
        for (j = 0; j < len; j++) {
          if (notes[j].day == day) {
            printf("|%2d| ",day);
            hasNote = 1;
            break;
          }
        }
        if (hasNote == 0) {
          printf("%2d   ",day);
        }
        if(i % 7 == 6)
            printf("\n");
    }   
    printf("\n");
    scanf("\n%c", &choice);
    if (choice == 's') {
      printf("Here are list of notes for %d %d\n", m, y);
      for (j = 0; j < len; j++) {
        printf("%d: %s\n", notes[j].day, notes[j].note);
      }
    } else {
      return;
    }
}