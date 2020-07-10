int AnnotationsManager::CrossSum(QString dbAnn, QString resAnn)
{
    int count = 0;
    QMap<uint32_t, QString>::iterator i;
    for (i = dbAnnotationsMap.begin(); i != dbAnnotationsMap.end(); ++i){
        if(CheckAnnotation(i.value()) == dbAnn)
        {
            if(CheckValue(i,resAnn))
            {
                count ++;
            }
        }
    }
    return count;
}