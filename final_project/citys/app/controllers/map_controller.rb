class MapController < ApplicationController

  def index
    generate_graph
  end

  private

  def generate_graph

    @graph = {}
    cities = City.all

    cities.each do |origin|
      distances = {}
      Distance.where(origin_id: origin.id).order('destiny_id').each do |d|
        distances[d.destiny.name] = { :name => d.destiny, :value => d.value }
      end
      @graph[origin.name] = distances
    end
    p @graph
  end

end
