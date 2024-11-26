package javabean;

import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.beans.PropertyVetoException;

public class JavaBean {
    public void run() {
        System.out.println("Running JavaBean experiment...");

        PersonBean person = new PersonBean();

        // Adding a property change listener
        person.addPropertyChangeListener(new PropertyChangeListener() {
            @Override
            public void propertyChange(PropertyChangeEvent evt) {
                System.out.println("Property changed: " + evt.getPropertyName() + 
                                   " [old -> " + evt.getOldValue() + 
                                   ", new -> " + evt.getNewValue() + "]");
            }
        });

        // Adding a vetoable change listener
        person.addVetoableChangeListener(evt -> {
            if ("age".equals(evt.getPropertyName())) {
                int newAge = (int) evt.getNewValue();
                if (newAge < 0 || newAge > 150) {
                    throw new PropertyVetoException("Age must be between 0 and 150.", evt);
                }
            }
        });

        // Modify properties
        person.setName("Alice");
        try {
            person.setAge(30); // Valid age
            person.setAge(-10); // Invalid age (will throw exception)
        } catch (PropertyVetoException e) {
            System.out.println("Veto: " + e.getMessage());
        }
    }
}
