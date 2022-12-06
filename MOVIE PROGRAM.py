import random

print("Welcome to movie plug/Popcorn ! The newest movie recommendation website. We have hundreds of movies to choose from, "
      "even international films! ")
print("Our genres include action, drama, comedy, romance, horror, IMDB movies, movie plug's/popcorn favorites, thriller, "
      "superheros, " "adventure, " "animated, crime, " " and western")
print("Enjoy!")
print(" ")

popcorn_movies =["The Dark Knight", "Intersteller", "Inception", "A Clockwork Orange",
                 "Inglorious Basterds", "Psycho", "Goodfellas", "Django Unchained"]
imdb_movies = ["The Shawshank Redemption", "The Godfather I", "The Godfather: Part II"]
comedy_movies = ["The Big Lebowski", "Dumb & Dumber", "Anchorman: The Legend of Ron Burgundy"]
romance_movies = ["Titanic", "The Notebook", "Call Me by Your Name"]
drama_movies = ["Schindler's List", "Atonement", "Good Will Hunting"]
horror_movies = ["The Exorcist", "The Shining", "Conjuring", "The Texas Chainsaw Massacre (1974)"]
thriller_movies = ["Seven", "Black Swan", "Mulholland Drive", "The Revenant"]


def question_one(answer):
      print("What genre of movie would you like to watch?")
      answer_one = input("Type here: ")
      a = "popcorn" #and "Popcorn"
      b = "imdb" #and "IMDB"
      c = "comedy" #and "Comedy"
      d = "romance" #and "Romance"
      e = "drama" #and "drama"
      f = "horror" #and "Horror"
      g = "thriller" #and "Thriller"

      if answer_one == a:
          print(" ")
          print(" ")
          print("You have selected the Popcorn section. Our recommended movies are " + str(popcorn_movies))
          print(" ")
      elif answer_one == b:
            print(" ")
            print(" ")
            print("You have selected the IMDb section. Our recommended movies are " + str(imdb_movies))
            print(" ")
      elif answer_one == c:
            print(" ")
            print(" ")
            print("You have selected the comedy section. Our recommended movies are " + str(comedy_movies))
            print(" ")
      elif answer_one == d:
            print(" ")
            print(" ")
            print("You have selected the romance section. Our recommended movies are " + str(romance_movies))
            print(" ")
      elif answer_one == e:
            print(" ")
            print(" ")
            print("You have selected the drama section. Our recommended movies are " + str(drama_movies))
            print(" ")
      elif answer_one == f:
            print(" ")
            print(" ")
            print("You have selected the horror section. Our recommended movies are " + str(horror_movies))
            print(" ")
      elif answer_one == g:
            print(" ")
            print(" ")
            print("You have selected the thriller section. Our recommended movies are " + str(thriller_movies))
            print(" ")

      print("Would you like to know the rating and year the movies were released?")
      answer_two = input("Enter yes or no: ")
      if answer_two == "yes" and answer_one == b:
            print(" ")
            print("The Shawshank Redemption: Released in 1994. IMDb rating: 9.3/10. Rotten Tomatoes rating: 91% ")
            print("The Godfather I: Released in 1972. IMDb rating: 9.1/10. Rotten Tomatoes: 97%")
            print("The Godfather: Part II: Released in 1974. IMDb rating: 9.0/10. Rotten Tomatoes: 96%")
      elif answer_two == "yes" and answer_one == a:
            print(" ")
            print("The Dark Knight: Released in 2008. IMDb rating: 9.0/10. Rotten Tomatoes rating: 94% ")
            print("Intersteller: Released in 2014. IMDb rating: 8.6/10. Rotten Tomatoes: 72%")
            print("Inception: Released in 2010. IMDb rating: 8.8/10. Rotten Tomatoes: 97%")
            print("Inception: Released in 2010. IMDb rating: 8.8/10. Rotten Tomatoes: 97%")







      #get the questions down




question_one("i")



