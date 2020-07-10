QwtTextLabel* MainUserGUI::selectElement(int dB, int res)
{
    QwtTextLabel* label;
    QLayoutItem* item = ui->gridLayout->itemAtPosition(dB,res);
    if (item != nullptr)
    {
        QWidget* widget = item->widget();
        if (widget != nullptr)
        {
            label = dynamic_cast<QwtTextLabel*>(widget);
        }else{
            label = nullptr;
        }
    }else{
        label = nullptr;
    }
    return label;
}