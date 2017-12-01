class CreateDistances < ActiveRecord::Migration[5.0]
  def change
    create_table :distances do |t|
      t.integer :origin_id
      t.integer :destiny_id
      t.integer :value

      t.timestamps
    end
  end
end
