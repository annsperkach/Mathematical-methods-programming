using System;
using System.Collections.Generic;
using System.Collections;

namespace Library
{
    public class DoubleList
    {
        Node Head;
        Node Tail;
        public int Size { get; private set; }
        public void FirstAdd(double data)
        {
            Node node = new Node(data);
            Node temp = Head;
            node.Next = temp;
            Head = node;
            if (Size == 0)
                Tail = Head;
            else
                temp.Previous = node;
            Size++;
        }

        public IEnumerator GetEnumerator()
        {
            Node current = Head;
            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }

        public double Sum()
        {
            Node current = Head;
            double sum = 0d;
            while (current != null)
            {
                sum += current.Data;
                current = current.Next;
            }
            return sum;
        }

        public int LessThanAverage()
        {
            Node current = Head;
            int counter = 0;
            double data;
            double sum = Sum();
            double Average = sum / Size;
            while (current != null)
            {
                data = current.Data;
                if (data < Average) counter++;
                current = current.Next;
            }
            return counter;
        }

        public bool Delete(double data)
        {
            Node current = Head;
            while (current != null)
            {
                if (current.Data.Equals(data))
                    break;
                current = current.Next;
            }
            if (current != null)
            {
                if (current.Next != null)
                {
                    current.Next.Previous = current.Previous;
                }
                else
                {
                    Tail = current.Previous;
                }
                if (current.Previous != null)
                {
                    current.Previous.Next = current.Next;
                }
                else
                {
                    Head = current.Next;
                }
                Size--;
                return true;
            }
            return false;
        }

        private Node FindMaxNode()
        {
            Node current = Head;
            Node max = current;

            while (current != null)
            {
                if (max.Data <= current.Data) max = current;
                current = current.Next;
            }
            return max;
        }

        public double MaxNode()
        {
            return FindMaxNode().Data;
        }

        public void DeleteToMax()
        {
            Node max = FindMaxNode();
            Node current = Tail;
            while (current != max)
            {
                current = current.Previous;
            }
            current = current.Previous;

            while (current != null)
            {
                Delete(current.Data);
                current = current.Previous;
            }
        }
    }
}
