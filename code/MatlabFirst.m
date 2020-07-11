function GetSampleAsText(sampleName,time)
%GETSAMPLEASTEXT(SampleName,SamplesAmount)
%   sampleName == 'mitdb/1xx'
%   time in minutes
[signal,Fs,tm]=rdsamp(sampleName,[],time * 21601);
output = [tm,signal].';


fileID = strrep(sampleName,'/','_');
file = fopen(strcat(fileID,'_',num2str(time),'.txt'),'wt');
fprintf(file,'%5.3f\n',Fs);
fprintf(file,'%5.4f,%3.4f,%3.4f\n',output);
fclose(file);
end