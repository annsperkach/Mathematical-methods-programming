using System;

namespace Lab6Polymorphism
{
    abstract public class Lines
    {
        abstract public int Length();
        abstract public void Decrement();
    }
    public class Symbols : Lines
    {
        private string str;
        public Symbols(string _str)
        {
            str = _str;
        }
        public override int Length()
        {
            return str.Length;
        }
        public override void Decrement()
        {
            string NewStr = "";
            int count = 1;
            while (count < str.Length)
            {
                NewStr += str[count];
                count += 2;
            }
            str = NewStr;
        }
        public string GetData()
        {
            return str;
        }
    }

    public class Numbers : Lines
    {
        private string str;
        public Numbers(string _str)
        {
            str = _str;
        }
        public override int Length()
        {
            return str.Length;
        }
        public override void Decrement()
        {
            string NewStr = "";
            int count = 0;
            while (count < str.Length)
            {
                NewStr += str[count];
                count += 2;
            }
            str = NewStr;
        }
        public string GetData()
        {
            return str;
        }
    }

}