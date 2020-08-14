#include "pch.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
    // Check for required argument
    if (args->Length < 1)
    {
        Console::WriteLine("Usage: CppReader path");
        return 0;
    }

    String^ path = args[0];

    if (!File::Exists(path))
    {
        Console::WriteLine("Invalid filename!");
        return -1;
    }

    try
    {
        FileStream^ fs = gcnew FileStream(path, System::IO::FileMode::Open);
        StreamReader^ sr = gcnew StreamReader(fs);

        int count = 0;
        for (;;)
        {
            String^ line = sr->ReadLine();
            count++;
            // If there are no more lines, break out of the loop
            if (line == nullptr) break;

            Console::WriteLine(line);

            if (count % 20 == 0)
            {
                Console::Write("--more--");
                String^ response = Console::ReadLine();
                if (response->Equals("q")) break;
                count = 0;
            }
        }
        Console::WriteLine("--end--");
    }
    catch (System::Exception^ pe)
    {
        Console::WriteLine(pe->Message);
    }
 

   
    return 0;
}
