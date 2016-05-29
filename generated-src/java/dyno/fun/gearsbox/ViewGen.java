// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

package dyno.fun.gearsbox;

public abstract class ViewGen {
    public abstract String getId();

    public abstract void setFrame(ViewFrame frame);

    public abstract ViewFrame getFrame();

    public abstract void setBackgroundColor(float a, float r, float g, float b);

    public abstract void setVisiable(boolean v);

    public abstract ViewGen getSubView(String id);

    public abstract boolean addSubView(String id, ViewType type);

    public abstract boolean removeSubView(String id);

    public abstract void removeAllSubView();

    public abstract void addConstraint(ViewConstraint constraint);

    public abstract void setEventHandler(ViewEventHandler handler);
}
