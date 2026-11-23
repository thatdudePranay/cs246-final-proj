/*
 * Example of using the <algorithm> std::shuffle and seeding a random number generator with either
 * the command-line argument provided seed integer, or the current system time if there is no
 * argument provided. Based off of the example at: 
 *
 *    http://www.cplusplus.com/reference/algorithm/shuffle/
 *
 *  Last updated: 2025-11-30
 *  Copyright 2025 UW. All rights reserved.
 *
 */
 
import <iostream>;
import <string>;
import <stdexcept>;
import <vector>;
import <algorithm>;
import <random>;
import <chrono>;

void print( std::vector<int> const & v ) {
    for ( int i : v ) std::cout << i << ' ';
    std::cout << std::endl;
} // print

int main( int argc, char * argv[] ) {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Use a time-based seed for the default seed value.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    
    if ( argc > 1 ) {
        try {
            // Try to convert the command-line argument to an integer. Raises an
            // exception if fails.
            seed = std::stoi( std::string{ argv[1] } );
        } catch( std::invalid_argument & e ) {
            std::cerr << e.what() << std::endl;
            return 1;
        } catch( std::out_of_range & e ) {
            std::cerr << e.what() << std::endl;
            return -1;
        } // catch
    } // if

    // Create the random number generator and "seed" it. Note that we generally only want
    // 1 of these, seeded only once, used throughout the program.
    std::default_random_engine rng{seed};

    // Shuffle the vector 1000 times and output the results.
    for ( int i = 0; i < 1000; i++ ) std::shuffle( v.begin(), v.end(), rng );       
    print(v);

    // Generate 5 random numbers in the range 1-10. Uses "rng" as a function object.
    for ( int i = 0; i < 5; ++i ) std::cout << (rng() % 10)+1 << std::endl;
    return 0;
} // main
