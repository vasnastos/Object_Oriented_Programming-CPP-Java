package bookstore;

import javax.swing.*;

public class Book {

  private String title, author;
  private int price;

  public Book(String t, String a, int p) {
    setTitle(t);
    setAuthor(a);
    setPrice(p);
  }

  public void setTitle(String t) {
    title = t;
  }

  public String getTitle() {
    return title;
  }

  public void setAuthor(String a) {
    author = a;
  }

  public String getAuthor() {
    return author;
  }

  public void setPrice(int p) {
    price = p;
  }

  public int getPrice() {
    return price;
  }

  @Override
  public String toString() {
    return title + ":" + author + ":" + price;
  }
}
