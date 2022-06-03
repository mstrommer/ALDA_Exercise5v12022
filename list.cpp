#include "list.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

list *l_init() {
    return NULL;
}

void l_insert(list * lst, char * word)
{
    
}

void l_delete(list * lst, char * word)
{
    
}

void l_print(list * lst) {

}

element *l_find(list * lst, char * word)
{
    return NULL;
}

int readFile(list* list, char* filename){
    // Parser von und mit Kommentaren von Herbert Paulis:
    FILE * file;
    char line[300];        // sicher lang genug fuer eine Zeile
    
    file = fopen("alice.txt", "r");
    
    if (!file) // bei Fehler wird NULL zurueckgegeben
    {
        printf("Fehler beim Oeffnen\n");
        return 1;
    }
    
    while (!feof(file))    // Solange nicht Dateiende erreicht wurde
    {
        fgets(line, 300, file);
        if (isspace(line[0]))  // Eliminieren von Leerzeilen
            continue;
        line[strcspn(line, "\r\n")] = 0; // ersetzt beliebeige Kombination von CR&LF durch 0
        //printf("%s\n", line);  // Testausgabe
        
        // Alternative fuer die folgende while-schleife: C-Funktion strtok()
        // https://en.cppreference.com/w/c/string/byte/strtok
        
        int zeilen_index = 0;   // Positionszaehler in der Zeile
        while (zeilen_index < strlen(line))
        {
            char wort[100];
            int wort_index = 0; // Positionszaehler im Wort
            int skip_extra = 0; // uebersprungene Zeichen
            
            for (int i = zeilen_index; i < strlen(line); i++)
            {
                if (line[i] == ' ')    // Leerzeichen
                {
                    if (i != zeilen_index)  // Wortende
                    {
                        break;
                    }
                    else                    // Zusätzliches Leerzeichen am Wort-/Zeilenanfang
                    {
                        skip_extra++;       // Merken, muessen spaeter dazugezaehlt werden
                        continue;
                    }
                }
                if (!isalpha(line[i])) // ueberspringe alles, was kein Buchstabe ist
                {
                    skip_extra++;       // Merken, muessen spaeter dazugezaehlt werden
                    continue;
                }
                wort[wort_index] = tolower(line[i]);   // Groszbuchsteben in Kleinbuchstaben umwandeln
                wort_index++;
            }
            wort[wort_index] = 0;
            zeilen_index += wort_index + skip_extra + 1;    // Zeilenindex korrigieren
            
            /*******************************************************************************/
            // Hier ist das jeweilige Wort in Variable wort enthalten zur spaeteren Weiterverarbeitung in der Liste
            // Achtung: wort kann Leerstring "" enthalten (z.B. wenn Zahl im Text war)!
            //printf("%s:", wort);    // Testausgabe
           
            element * tmp;
            
            // TODO
            // Hier müssen die Elemente noch in die Liste hinzugefügt werden.
            // Aber Vorsicht. Nicht doppelt...
            // list wird als Parameter der Funktion readFile übergeben.
            
            /*******************************************************************************/
        }
        //printf("\n");   // Nur fuer Testausgabe
    }
    return 0;
}

void frequencyCount(list *list, int *frequencies){
    
}

int letterCount(list *list){
    return 0;
}

int wordCount(list *list){
    return 0;
}

void deleteWords(list *list, int frequency){
    // Hinweis:
    // In unserem Fall wird für frequency z.B. 100 übergeben. Alle
    // Wörter mit einer geringeren Frequenz/Häufigkeit werden gelöscht.
}
