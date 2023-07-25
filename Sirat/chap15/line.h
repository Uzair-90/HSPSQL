#ifndef HEADER_FILE_H
#define HEADER_FILE_H

#define MAX_LINE_LEN 60

extern char line[MAX_LINE_LEN + 1];

void add_word(const char* word);
int space_remaining(void);
void write_line(void);
void flush_line(void);

#endif

