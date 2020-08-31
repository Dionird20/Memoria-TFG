
void buffer::BufferStorage()
{
    double res[bufferLength];
    for (int i = 0; i < bufferLength; i++) {
        res[i] = i;
    }
    circularBuffer buffer;
    buffer.InitializeBuffer();
    for (int i = 0; i < bufferLength; i++) {
        buffer.AppendSample(i);
    }
    for (int i = 0; i < bufferLength; i++) {
        QCOMPARE(res[i], buffer.GetSampleInverted(i));
        QCOMPARE(res[bufferLength - i - 1], buffer.GetSample(i));
    }
}

void buffer::BufferCircularity()
{
    circularBuffer buffer;
    buffer.InitializeBuffer();
    QCOMPARE(buffer.GetLength(), 1024);
    for (int i = 0; i < 2 * bufferLength; i++) {
        buffer.AppendSample(i);
    }
    for (int i = 0; i < bufferLength; i++){
        QCOMPARE(double(bufferLength + i), buffer.GetSampleInverted(i));
        QCOMPARE(double(2 * bufferLength - i - 1), buffer.GetSample(i));
    }
    buffer.InitializeBuffer();
    for (int i = 0; i < bufferLength + 512; i++) {
        buffer.AppendSample(i);
    }
    for (int i = 0; i < bufferLength; i++){
        QCOMPARE(double(512 + i), buffer.GetSampleInverted(i));
        QCOMPARE(double((bufferLength + 512) - i - 1), buffer.GetSample(i));
    }
}

