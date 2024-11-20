module MoviesHelper
    # Toggle the sort direction for the column
    def toggle_direction(column)
      if params[:sort] == column && params[:direction] == 'asc'
        'desc'
      else
        'asc'
      end
    end
  
    # Show an arrow indicating the sort direction
    def sort_indicator(column)
      if params[:sort] == column
        params[:direction] == 'asc' ? '↑' : '↓'
      else
        ''
      end
    end
  end
  