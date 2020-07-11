void TestAnnotations::CorrectFromfiles(){
    isDBAnn = true;
    InitializeAnnManager();
    ReadFile readFile;
    connect(&readFile,SIGNAL(FileReadedAnnotation(uint32_t,QString)),
            this,SLOT(FileReadedAnnSlot(uint32_t,QString)));
    readFile.SetPath("<FilePAth>/Data/AnnTestDB.txt");
    readFile.Read();
    while(!readFile.IsEOF()){
        readFile.Read();
    }
    isDBAnn = false;
    readFile.SetPath("<FilePath>/Data/AnnTestRes.txt");
    readFile.Read();
    while(!readFile.IsEOF()){
        readFile.Read();
    }
    int results[7][7];
    int e_results[7][7];
    for (int i = 0;i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            results[i][j] = 0;
            e_results[i][j] = 0;
        }
    }
    for (int i = 1;i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int sum = annManager.CrossSum(annManager.GetAnnotationChar(i),
                annManager.GetAnnotationChar(j));
            results[i][j] = sum;
        }
    }
    for (int i = 1;i <= 5; i++) {
        int sum = annManager.CalculateFN(annManager.GetAnnotationChar(i));
        results[6][i] = sum;
    }
    for (int i = 1;i <= 5; i++) {
        int sum = annManager.CalculateFP(annManager.GetAnnotationChar(i));
        results[i][6] = sum;
    }
    e_results[1][1] = 1; e_results[2][2] = 1;
    e_results[3][3] = 1; e_results[4][4] = 1;
    e_results[5][5] = 1; e_results[1][3] = 1;
    e_results[3][2] = 1; e_results[1][4] = 1;
    e_results[1][6] = 1; e_results[6][1] = 1;
    for (int i = 0;i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            QCOMPARE(results[i][j],e_results[i][j]);
        }
    }
}