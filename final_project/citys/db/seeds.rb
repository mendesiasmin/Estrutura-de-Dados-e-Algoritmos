# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rails db:seed command (or created alongside the database with db:setup).
#
# Examples:
#
#   movies = Movie.create([{ name: 'Star Wars' }, { name: 'Lord of the Rings' }])
#   Character.create(name: 'Luke', movie: movies.first)

puts "Create cities..."
city_a = City.create(name: 'Águas Claras')
city_b = City.create(name: 'Brasília')
city_c = City.create(name: 'Ceilândia')
city_d = City.create(name: 'Taguatinga')
city_e = City.create(name: 'Samambaia')
city_f = City.create(name: 'Guará')
city_g = City.create(name: 'Gama')
city_h = City.create(name: 'Valparaíso')


puts "Create distances betwen cities..."
Distance.create(origin: city_a, destiny: city_b, value: 20)
Distance.create(origin: city_a, destiny: city_d, value: 80)
Distance.create(origin: city_a, destiny: city_g, value: 90)
Distance.create(origin: city_b, destiny: city_f, value: 10)
Distance.create(origin: city_c, destiny: city_f, value: 50)
Distance.create(origin: city_c, destiny: city_h, value: 20)
Distance.create(origin: city_c, destiny: city_d, value: 10)
Distance.create(origin: city_d, destiny: city_d, value: 10)
Distance.create(origin: city_d, destiny: city_g, value: 20)
Distance.create(origin: city_e, destiny: city_g, value: 30)
Distance.create(origin: city_e, destiny: city_b, value: 50)
Distance.create(origin: city_f, destiny: city_c, value: 10)
Distance.create(origin: city_f, destiny: city_d, value: 40)
Distance.create(origin: city_g, destiny: city_a, value: 20)
