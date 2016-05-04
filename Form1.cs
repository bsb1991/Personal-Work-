using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace Project
{
    public partial class Form1 : Form
    {
        // Declare class variables
        public List<string> Data = new List<string> { };
        public List<string> replaceableList = new List<string> { };
        public string FileName;
        public Form1()
        {
            InitializeComponent();
        }

        private void ScrubData()
        {
            // Put each line of the text file into an array
            string[] preParse = File.ReadAllLines(FileName);

            // Instance a new StringBuilder to append items into a text string
            StringBuilder builder = new StringBuilder();

            // Foreach item in the array preParse, append text in the StringBuilder.
            foreach (string item in preParse)
            {
                builder.Append(item);
                builder.Append("-");
                Data.Add(item);
            }

            StringBuilder builder2 = new StringBuilder();
            foreach (string item in Data)
            {
                // Append the item to the string builder
                builder2.Append(item);
            }

            // Call the ReplaceData() void
            ReplaceData();
        }

        private void ReplaceData()
        {
            StringBuilder builder = new StringBuilder();
            foreach (string item in Data)
            {
                // Add items to the secondary list for replacing.
                replaceableList.Add(item);
                builder.Append(item);
            }

            //Console.WriteLine(Data.Count);
            foreach (string item in Data)
            {
                // Write all items out to the console.
                Console.WriteLine(item);
                List<string> items = new List<string> { };

                string[] itemAr = item.Split('|');

                foreach (string item2 in itemAr)
                {
                    items.Add(item2);
                }

                // Replace the first item in the array with a random sequence of strings and integers.
                items[0] = GetRandomMix(7);
                items[2] = GetRandomString(items[2].Length);
                items[3] = replaceX(items[3]);


                StringBuilder builder2 = new StringBuilder();

                int index = 0;
                Console.WriteLine(items.Count);
                foreach (string item3 in items)
                {
                    // Append the item with the replace key to replace later.
                    builder2.Append("rplace" + index.ToString());

                    // \r\n inserts a new line / linebreak
                    builder2.Append("\r\n");
                    builder2.Append(item3);
                    builder2.Append("\r\n");

                    // increment the index by one.
                    index++;
                }


                string parsedData = builder2.ToString();

                // Create a new string from the StringBuilder and replace the replacement keys.
                parsedData = parsedData.Replace("rplace0", "Random Numbers:");
                parsedData = parsedData.Replace("rplace1", "First Name:");
                parsedData = parsedData.Replace("rplace2", "Last Name:");
                parsedData = parsedData.Replace("rplace3", "Show only the last four of the Credit Card");
                parsedData = parsedData.Replace("rplace4", "Price:");
                parsedData = parsedData.Replace("rplace5", "Spent On:");

                // Set the counter / index back to 0 for the next list
                index = 0;


                // If the price is over 100, set 'yes'.
                if (float.Parse(items[4]) > 100)
                {
                    builder2.Append("yes");
                }
                else
                {
                    builder2.Append("no");
                }

                // Path to save the file to
                string path = Path.Combine("C:/Users/" + Environment.UserName + "/Desktop", "data_scrubbed.txt");

                string fileContents = String.Empty;

                if (File.Exists(path))
                {
                    // If the scrub file already exists, get the contents of it.
                    fileContents = File.ReadAllText(path);
                }

                // Write the contents to the file.
                File.WriteAllText(path, fileContents + parsedData + "\r\n");
            }
            string scrubbedPath = Path.Combine("C:/Users/" + Environment.UserName + "/Desktop", "data_scrubbed.txt");
        }

        // 'Void' for returning a random sequence of numbers and letters.

        private string replaceX(string item)
        {
            List<char> itemList = new List<char> { };
            foreach (char i in item)
            {
                //Add the character to the list
                itemList.Add(i);
            }

            foreach (char item2 in itemList)
            {
                // Write the item out to the console
                Console.Write(item2);
            }

            int itemListLength = itemList.Count;

            // Get a new string that contains 13 random chars
            string newString = randomX(13);

            newString = newString + itemList[itemListLength - 4] + itemList[itemListLength - 3] + itemList[itemListLength - 2] + itemList[itemListLength - 1];

            return newString;
        }
        private string GetRandomMix(int Size)
        {
            Random random = new Random();
            string input = "0123456789";
            StringBuilder builder = new StringBuilder();
            char ch;
            for (int i = 0; i < Size; i++)
            {
                ch = input[random.Next(0, input.Length)];
                builder.Append(ch);
            }
            return builder.ToString();
        }

        public string GetRandomString(int Size)
        {
            Random random = new Random();
            string input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            StringBuilder builder = new StringBuilder();
            char ch;
            for (int i = 0; i < Size; i++)
            {
                // Foreach number in the size int, add a random letter from the string into the new string builder.
                ch = input[random.Next(0, input.Length)];
                builder.Append(ch);
            }

            // Return the random string
            return builder.ToString();
        }

        public string randomX(int Size)
        {
            StringBuilder builder = new StringBuilder();
            char ch;
            for (int i = 0; i < Size; i++)
            {
                // Add x to the string
                ch = 'x';
                builder.Append(ch);
            }
            return builder.ToString();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            // If no file was selected, return an error.
            if (String.IsNullOrEmpty(FileName))
            {
                MessageBox.Show("Please select a file.");
                return;
            }

            ScrubData();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Use an Open File Dialog to select the file with the information
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog();

            if (!ofd.FileName.Contains("data.txt"))
            {
                MessageBox.Show("Please upload data.txt");
                return;
            }

            FileName = ofd.FileName;
        }
    }
}
