using System;

namespace MyLibrary
{
    class MyString
    {
        private int NumberOfStrings = 0;
        private string[] OurStrings;


        public int Length 
        {
            get
            { 
                return NumberOfStrings; 
            }
        }

        public void ControlAccess()
        {
            {
                for (int i = OurStrings.Length - 1; i >= 0; i--)
                {
                    Console.WriteLine(OurStrings[i]);
                }
                Console.WriteLine();
            }
        }

        public string this[int index]  
        {
            get
            {
                return OurStrings[index];
            }
            set
            {
                OurStrings[index] = value;
            }
        }

        public void AddString(string str)
        {
            ++NumberOfStrings;
            string[] NewStrings = new string[NumberOfStrings];
            NewStrings[NumberOfStrings - 1]=str;

            for (int i = 0; i < NumberOfStrings - 1; i++)
            {
                NewStrings[i] = OurStrings[i];
            }

            OurStrings = NewStrings;
        }

        public void AddString(int PositionInArray, string str)
        {
            if (PositionInArray >= NumberOfStrings)
            {
                AddString(str);
            }
            else
            {
                ++NumberOfStrings;
                string[] NewStrings = new string[NumberOfStrings];

                for (int i = 0; i < PositionInArray; i++)
                {
                    NewStrings[i] = this.OurStrings[i];
                }
                NewStrings[PositionInArray] = str;

                for (int i = PositionInArray + 1; i < NumberOfStrings; i++)
                {
                    NewStrings[i] = this.OurStrings[i - 1];
                }
                this.OurStrings = NewStrings;
            }
        }

    }
}