class MapController < ApplicationController

  def index
    @cities = City.all.order("name")
  end

  def dijkstra
    origin_id = params[:origin]
    graph = generate_graph
#    destin = params[:destin]
    distance = [-1] * City.count
    cities = City.all.pluck(:name)
    hash_data = Hash(cities.sort.zip(distance).to_h)
    p hash_data

    origin = City.find(origin_id).name
    @origin = origin
    actual_city = origin
    hash_data[actual_city] = {origin: actual_city, distance: 0, visited: true, city: actual_city }
    for index in 0..City.count
      graph[actual_city].each do |destiny|
        distance = destiny[1] + hash_data[actual_city][:distance]
        if hash_data[destiny[0]] == -1
          hash_data[destiny[0]] = {origin: actual_city, distance: distance, visited: false, city: destiny[0] }
        elsif distance < hash_data[destiny[0]][:distance]
          hash_data[destiny[0]] = {origin: actual_city, distance: distance, visited: false, city: destiny[0] }
        end
      end
      smallest = -1
      hash_data.each do |data|
        compare = data[1]
        if compare != -1
          unless compare[:visited]
            if smallest == -1
              smallest = {city: compare[:city], distance: compare[:distance]}
            elsif compare[:distance] < smallest[:distance]
              smallest = {city: compare[:city], distance: compare[:distance]}
            end
          end
        end
      end
      if smallest == -1
        break
      end
      actual_city = smallest[:city]
      hash_data[actual_city][:visited] = true

    end
    p "a"*80
    p hash_data
    p "a"*80

    @result = hash_data

    respond_to do |format|
      format.html
    end

  end

  private

  def generate_graph

    graph = {}
    cities = City.all

    cities.each do |origin|
      distances = {}
      Distance.where(origin_id: origin.id).order('destiny_id').each do |d|
        distances[d.destiny.name] = d.value
      end
      graph[origin.name] = distances
    end
    p graph
    graph
  end

end
