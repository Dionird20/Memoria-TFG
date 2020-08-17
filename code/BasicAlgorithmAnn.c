ecgProcesedSamples_m BasicPeakAlgorithm(circularBuffer_t *buffer)
{
    ecgProcesedSamples_m aux;
    int16_t i;
    uint8_t rCount = 0;
    for(i=0;i<sampleCount;i++){
        if(GetSample(buffer,i) > threshold)
        {
            if(IsLocalMax(buffer,i,5))
            {
                aux.rPeaks[rCount] = GetAbsoluteSample(buffer,i);
                aux.values[rCount] = GetSample(buffer,i);
                aux.annotations[rCount] = 'N';
                rCount ++;
            }
        }
    }
    aux.threshold = threshold;
    aux.peaksAmount = rCount;
    return aux;
}

bool IsLocalMax(circularBuffer_t *buffer, int16_t iterator ,int8_t size ){
    if (size % 2 == 0){
        size -= 1;
    }
    int8_t middle = (size/2);
    int8_t i;
    bool result = true;
    for (i=0; i<size; i++){
        if(i < middle){
            result = GetSample(buffer,iterator+i-middle) < 
                    GetSample(buffer,iterator) && result;
        }else if(i > middle){
            result = GetSample(buffer,iterator+i-middle) < 
                    GetSample(buffer,iterator) && result;
        }
    }
    return result;
}