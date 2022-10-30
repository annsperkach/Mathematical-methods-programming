using System;
using System.Collections.Generic;

namespace Library
{
    public class Node
    {
        public Node Next { get; set; }
        public Node Previous { get; set; }
        public double Data { get; set; }
        public Node(double data)
        {
            Data = data;
        }
    }
}
