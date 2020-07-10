int AnnotationsManager::CalculateFP(QString ann)
{
    int count = 0;
    QMap<uint32_t, QString>::iterator i;
    for (i = resultAnnotationsMap.begin(); i != resultAnnotationsMap.end(); ++i){
        if( i.value() == ann)
        {
            bool found = false;
            for (uint32_t j = 0;j <= tolerance; j++) {
                if(dbAnnotationsMap.contains(i.key()+j))
                {
                    found = true;
                }
                if (dbAnnotationsMap.contains(i.key()-j) && j <= i.key())
                {
                    found = true;
                }
            }
            if(!found)
            {
                count++;
            }
        }
    }
    return count;
}