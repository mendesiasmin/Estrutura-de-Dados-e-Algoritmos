module MapHelper

  def indexed_graph
    cities = City.all.order(:name)
    index = 0
    hash = {}
    cities.each do |city|
      key = city.name
      hash[key] = index
      index += 1
    end
    hash
  end

  def row city, cities
    row = []
    index = 0
    city.each do |destiny|
      while (cities.key index) != destiny do
        row.push_back(0)
        index += 1
      end
        row.push_back(cities[destiny])
    end
    row
  end

end
