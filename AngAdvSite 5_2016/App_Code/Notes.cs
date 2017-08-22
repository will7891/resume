using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net;
using System.Web;
using System.Web.UI;
using System.Web.Script.Serialization;


/// <summary>
/// Summary description for Notes
/// </summary>
public class Notes 
{
	public static void Main()
   {
       

     
  
   
   }
} // Notes
/*
class Item : IEquatable<Item>
{
  public int id;
  public string title;
  public string description;

  public Item(int id, string title, string description)
  {
    this.id = id;
    this.title = title;
    this.description = description;
  }

  public static bool operator == (Item first, Item other)
  {
    if (other == null) return false;
    return (first.title == other.title);
  }

  public static bool operator !=(Item first, Item second)
  {
      if (second == null) return true;
      return (first.title != second.title);
  }

  public bool Equals(Item thing)
  {
      return this.title == thing.title;
  } 
 
} // Item

class Program
{
  static void Main(string[] args)
  {

  }

  public void Button1_Click(object sender, EventArgs e)
  {
      string jsonSTRING = File.ReadAllText("data/notes.json");
      List<Item> myList = new JavaScriptSerializer().Deserialize<List<Item>>(jsonSTRING);

      var serializer = new JavaScriptSerializer();
      var serializedResult = serializer.Serialize(myList);
      File.WriteAllText("data/notes.json", serializedResult);
  }

  
} // Program 
*/