// Types definitions
typedef PARAMETERS_ECG_PROCESSED (*ECGProcessingFunc)(circularBuffer_t *buffer);

// Functions definitions
void ECGProcessingConfig(uint16_t freq, circularBuffer_t *buffer);
void SetECGProcessor(void);

// External variables
extern ECGProcessingFunc ECGProcessor;

// User functions definitions
PARAMETERS_ECG_PROCESSED BasicPeakAlgorithm(circularBuffer_t *buffer);

======================================================================

// SetECGProcessor fullfill the pointer with the function.
void SetECGProcessor(void)
{
    ECGProcessor = &BasicPeakAlgorithm;
}

// ECGProcessingConfig configures and initialize the necesary variables for the ECG
// process. this function is executed once each time a new signal is introduced or
// when any parameter changes.
void ECGProcessingConfig(uint16_t inputFreq, circularBuffer_t *buffer)
{
    ... //User can use this function for inicialization.
}

// Function defined by the user
PARAMETERS_ECG_PROCESSED BasicPeakAlgorithm(circularBuffer_t *buffer)
{
    ...
}