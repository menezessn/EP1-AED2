int readFirstLine (char *imgFileName) {
    int numVertices
    int i;
	FILE *fp;
	fp= fopen(imgFileName, "r");
	int i=0;
        
		fscanf (fp, "%d\n", &(M[i]));
		printf ("\nconteudo: %d ", M[i]);
		++i;
	}
	fclose(fp);
}