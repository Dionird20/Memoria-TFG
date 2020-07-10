void AnnotationsManager::AddDbAnnotation(uint32_t sample, QString annotation)
{
    if(!dbAnnotationsMap.contains(sample))
    {
        dbAnnotationsMap[sample] = annotation;
    }
}

void AnnotationsManager::AddResultAnnotation(uint32_t sample, QString annotation)
{
    resultAnnotationsMap[sample] = annotation;
    for (uint32_t i = 1;i <= tolerance; i++) {
        if (resultAnnotationsMap.contains(sample + i))
        {
            resultAnnotationsMap.remove(sample + i);
        }
        if (resultAnnotationsMap.contains(sample - i) && i <= sample)
        {
            resultAnnotationsMap.remove(sample - i);
        }
    }
}