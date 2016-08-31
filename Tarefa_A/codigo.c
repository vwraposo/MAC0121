char *readLine (FILE * infile) {
   char *line, nline;
   int n, ch, size;
   n = 0;
   size = 120;
   line = malloc (size + 1);
   while ((ch = getc (infile)) != '\n' && ch != EOF) {
      if (n == size) {
         size *= 2;
         nline = malloc (size + 1);
         strncpy (nline, line, n);
         free (line);
         line = nline;
      }
      line[n++] = ch;
   }
   if (n == 0 && ch == EOF) {
      free (line);
      return NULL;
   }
   line[n] = '\0';
   nline = malloc (n + 1);
   strcpy (nline, line);
   free (line);
   return nline;
}