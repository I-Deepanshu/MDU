package javabean;

import java.beans.*;
import java.io.Serializable;

public class PersonBean implements Serializable {
    private String name;
    private int age;

    private final PropertyChangeSupport propertyChangeSupport;
    private final VetoableChangeSupport vetoableChangeSupport;

    public PersonBean() {
        propertyChangeSupport = new PropertyChangeSupport(this);
        vetoableChangeSupport = new VetoableChangeSupport(this);
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Setter for name (bound property)
    public void setName(String name) {
        String oldName = this.name;
        this.name = name;
        propertyChangeSupport.firePropertyChange("name", oldName, name);
    }

    // Getter for age
    public int getAge() {
        return age;
    }

    // Setter for age (constrained property)
    public void setAge(int age) throws PropertyVetoException {
        int oldAge = this.age;
        vetoableChangeSupport.fireVetoableChange("age", oldAge, age);
        this.age = age;
        propertyChangeSupport.firePropertyChange("age", oldAge, age);
    }

    // Add/remove property change listeners
    public void addPropertyChangeListener(PropertyChangeListener listener) {
        propertyChangeSupport.addPropertyChangeListener(listener);
    }

    public void removePropertyChangeListener(PropertyChangeListener listener) {
        propertyChangeSupport.removePropertyChangeListener(listener);
    }

    // Add/remove vetoable change listeners
    public void addVetoableChangeListener(VetoableChangeListener listener) {
        vetoableChangeSupport.addVetoableChangeListener(listener);
    }

    public void removeVetoableChangeListener(VetoableChangeListener listener) {
        vetoableChangeSupport.removeVetoableChangeListener(listener);
    }
}
