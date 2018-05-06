#ifndef MVCINTERFACES
#define MVCINTERFACES

#include <vector>

/// Author: Wald Habets

/**
 * !! This is an abstract class
 * This class defines the basic interface for views
 */
class ViewInterface {
public:
	/**
	 * This method must be overridden in the implementing class
     * This method must be called by the model when changes occur in said model
	 * The implementation of the method should update the view based on data from the model
	 */
	virtual void update() = 0;
};

/**
 * This class defines the basic interface for models
 * This class holds all Views inherited from ViewInterface that observe the models
 * Views observing the model shall be updated via the method update() when changes in the model occur
 * 
 * !! The client user should inherit his own model from this class
 * !! ModelInterface should not be used on its own
 */
class ModelInterface {
public:
	ModelInterface() {
		_is_changed = false;
	}
	~ModelInterface() {
        _views.clear();
	}
	
	/**
	 * Adds a new view as an object observing the model
	 * @param view - The view that has to be added to the list of observing objects
	 */
    void addView(ViewInterface* view) {
        _views.push_back(view);
	}
	
	/**
	 * Removes the specified view from the list of observing objects
	 * @param view - The view that has to be deleted from the list of observing objects
	 * @return a pointer to the removed object, null if nothing was removed
	 */
    ViewInterface* removeView(ViewInterface* view) {
        int i = 0;
        while(_views[i] != view && i < _views.size()) { i++; }
		
		if (i < _views.size()) { 
            _views.erase(_views.begin() + i);
            return view;
		}
		
        return NULL;
	}

	/**
	 * Calls the update method for all views observing the model
	 * !! this method will automatically call setChanged(false)
	 */
	void updateViews() { 
        for (ViewInterface* view: _views) { view->update(); }
		setChanged(false);
	}
	
	/**
	 * Returns whether there has been any changes to the model since the last update
	 * @return true or false whether changes have been made or not
	 */
	bool isChanged() { return _is_changed; }
	
	/**
	 * Changes the state of the object based on whether or not changes have been made since the last update to the views
	 * @param is_changed - should be true if changes have been made, false otherwise
     */
	void setChanged(bool is_changed) { _is_changed = is_changed; }
private:
    std::vector<ViewInterface*> _views;
	bool _is_changed;
};

#endif // MVCINTERFACES
