#! /usr/bin/env ruby
# Example of a class

require './steward.rb'

name = [ "Sussane", "Cindy", "Stacy", "Caroline", "Claire", "Chloe", "Sthepanie", "Lucy"]
steward = []
7.times{ |x| steward.push( Steward.new ( name[x] ) ) }

puts "We have #{Steward.count} stewards."

staff.each { |s| s.greet "Txema" }
