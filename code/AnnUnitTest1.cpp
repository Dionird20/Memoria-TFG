void TestAnnotations::AddAnnotations()
{
    AnnotationsManager annManager;
    annManager.SetTolerance(2);
    annManager.AddDbAnnotation(1,"N");
    annManager.AddResultAnnotation(1,"N");
    QMap<uint32_t,QString> db;
    db[1] = "N";
    QCOMPARE(db, annManager.GetDbAnnotations());
    QMap<uint32_t,QString> result;
    result[1] = "N";
    QCOMPARE(result, annManager.GetResultAnnotations());
}

void TestAnnotations::CrossSum()
{
    AnnotationsManager annManager;
    annManager.SetTolerance(2);
    annManager.AddDbAnnotation(1,"N");
    annManager.AddDbAnnotation(5,"N");
    annManager.AddResultAnnotation(1,"N");
    annManager.AddResultAnnotation(5,"N");
    int count = annManager.CrossSum("N","N");
    QCOMPARE(count,2);
}
