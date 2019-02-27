#pragma once

#include <Formats/FormatSettings.h>
#include <Processors/Formats/IRowOutputFormat.h>


namespace DB
{

class WriteBuffer;


/** A stream for outputting data in the VALUES format (as in the INSERT request).
  */
class ValuesRowOutputFormat : public IRowOutputFormat
{
public:
    ValuesRowOutputFormat(WriteBuffer & out, Block header, const FormatSettings & format_settings);

    String getName() const override { return "ValuesRowOutputFormat"; }

    void writeField(const IColumn & column, const IDataType & type, size_t row_num) override;
    void writeFieldDelimiter() override;
    void writeRowStartDelimiter() override;
    void writeRowEndDelimiter() override;
    void writeRowBetweenDelimiter() override;

private:
    const FormatSettings format_settings;
};

}
