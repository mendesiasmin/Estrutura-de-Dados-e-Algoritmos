class City < ApplicationRecord
  has_many :distance, :class_name => 'Distance'
end
