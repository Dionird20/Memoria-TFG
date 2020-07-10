function GetSampleAsTextWithAnnotations(sampleName,time)
%GetSampleAsTextWithAnnotations(SampleName,SamplesAmount)
%   sampleName == 'mitdb/1xx'
%   time in minutes
[signal,Fs,tm]=rdsamp(sampleName,[],time * 21601);
[ann,annType]=rdann(sampleName, 'atr',[],length(signal),[],[]);

anns = cell(1,length(signal));
validAnnTypes = ['N','S','V','F','J','/','Q'];

for i = 1:length(anns)   
    anns{1,i} = '';
end

for i = 1:length(ann)
    for j= 1:length(validAnnTypes)
        if (annType(i,1) == validAnnTypes(j))
            if (annType(i,1)=='J'), annType(i,1) = 'N'; end
            if (annType(i,1)=='Q'), annType(i,1) = 'N'; end
            if (annType(i,1)=='/'), annType(i,1) = 'Q'; end
            anns{1,ann(i,1)} = [anns{1,ann(i,1)},annType(i,1)];
        end
    end
end

output = [tm,signal].';

fileID = strrep(sampleName,'/','_');
file = fopen(strcat(fileID,'_',num2str(time),'.txt'),'wt');
fprintf(file,'%5.3f\n',Fs);

for i= 1:length(output)
    fprintf(file,'%5.4f,%3.4f,%3.4f',output(:,i));
    fprintf(file,',%s\n',anns{:,i});
end

fclose(file);
end